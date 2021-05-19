#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdbool.h>
#include<iostream>
#include<cmath>
#include<string>
#include <cstdlib>
#include<ctime>
#include "game.h"
#include "card.h"
#include "util.h"

ALLEGRO_BITMAP* cardBack;
ALLEGRO_BITMAP* backGround;
ALLEGRO_BITMAP* colorSelect;
ALLEGRO_BITMAP* colorSelectB;
ALLEGRO_BITMAP* colorSelectY;
ALLEGRO_BITMAP* colorSelectG;
ALLEGRO_BITMAP* colorSelectR;
ALLEGRO_BITMAP* colorSelectCurrent;
ALLEGRO_BITMAP* mainMenu;
ALLEGRO_BITMAP* drawButton;
ALLEGRO_BITMAP* passButton;
ALLEGRO_BITMAP* playButton;
ALLEGRO_BITMAP* unoButton;

ALLEGRO_TIMER* timer;
ALLEGRO_EVENT_QUEUE* queue;
ALLEGRO_DISPLAY* disp;
ALLEGRO_FONT* font;

int ClickedCard() {
  ALLEGRO_MOUSE_STATE state;
  al_get_mouse_state(&state);
  int PlayerSize = activePlayer()->get_hand()->get_cards().size();
  for (int i = 0; i < PlayerSize; i++) {
    int cardPosX = (al_get_display_width(al_get_current_display())/2) - (50 * PlayerSize) + (100 * i);
    int cardPosY = al_get_display_height(al_get_current_display()) - 182;
    if (state.x > cardPosX && state.x < cardPosX + 130 && state.y > cardPosY && state.y < cardPosY + 182) {
      return i;
    }
  }
  return -1;
}

void drawMenu () {

}

void drawTwo(bool show) {

}

void drawFour(bool show) {
  int playerNumber = game.get_players();
  int activePlayerSize = 0;
  double playerScale = 0.5;
  int cardWidth = 130;
  int cardHeight = 182;

  al_draw_scaled_bitmap(backGround,
    0, 0,                                // source origin
    cardWidth, cardHeight,
    0, 0,                                // target origin
    1200, 900 ,                                // target dimensions
    0                                    // flags
  );

  if (show) {
    Player* drawPlayer = game.get_playerList().at((game.get_activePlayer()+1)%playerNumber);
    activePlayerSize = drawPlayer->get_hand()->get_cards().size();

    for (int j = 0; j < drawPlayer->get_hand()->get_cards().size(); j++) {
      al_draw_scaled_rotated_bitmap(drawPlayer->get_hand()->get_cards().at(j)->get_sprite(),
      0, 0,
      (182 * playerScale), (al_get_display_height(al_get_current_display())/2) - (25 * activePlayerSize) + (50 * j),
      playerScale, playerScale,
      M_PI/2, 0);
    }

    drawPlayer = game.get_playerList().at((game.get_activePlayer()+2)%playerNumber);
    activePlayerSize = drawPlayer->get_hand()->get_cards().size();
    for (int j = 0; j < drawPlayer->get_hand()->get_cards().size(); j++) {
      al_draw_scaled_rotated_bitmap(drawPlayer->get_hand()->get_cards().at(j)->get_sprite(),
      0, 0,
      (al_get_display_width(al_get_current_display())/2) - (25 * activePlayerSize) + (50 * j), (182 * playerScale),
      playerScale, playerScale,
      M_PI, 0);
    }

    drawPlayer = game.get_playerList().at((game.get_activePlayer()+3)%playerNumber);
    activePlayerSize = drawPlayer->get_hand()->get_cards().size();
    for (int j = 0; j < drawPlayer->get_hand()->get_cards().size(); j++) {
      al_draw_scaled_rotated_bitmap(drawPlayer->get_hand()->get_cards().at(j)->get_sprite(),
      0, 0,
      al_get_display_width(al_get_current_display()) - (182 * playerScale), (al_get_display_height(al_get_current_display())/2) - (25 * activePlayerSize) + (50 * j),
      playerScale, playerScale,
      -M_PI/2, 0);
    }
  } else {
    Player* drawPlayer = game.get_playerList().at((game.get_activePlayer()+1)%playerNumber);
    activePlayerSize = drawPlayer->get_hand()->get_cards().size();
    for (int j = 0; j < activePlayerSize; j++) {
      al_draw_scaled_rotated_bitmap(cardBack,
      0, 0,
      (182 * playerScale), (al_get_display_height(al_get_current_display())/2) - (25 * activePlayerSize) + (50 * j),
      playerScale, playerScale,
      M_PI/2, 0);
    }

    drawPlayer = game.get_playerList().at((game.get_activePlayer()+2)%playerNumber);
    activePlayerSize = drawPlayer->get_hand()->get_cards().size();
    for (int j = 0; j < activePlayerSize; j++) {
      al_draw_scaled_rotated_bitmap(cardBack,
      0, 0,
      (al_get_display_width(al_get_current_display())/2) - (25 * activePlayerSize) + (50 * j), (182 * playerScale),
      playerScale, playerScale,
      M_PI, 0);
    }

    drawPlayer = game.get_playerList().at((game.get_activePlayer()+3)%playerNumber);
    activePlayerSize = drawPlayer->get_hand()->get_cards().size();
    for (int j = 0; j < activePlayerSize; j++) {
      al_draw_scaled_rotated_bitmap(cardBack,
      0, 0,
      al_get_display_width(al_get_current_display()) - (182 * playerScale), (al_get_display_height(al_get_current_display())/2) - (25 * activePlayerSize) + (50 * j),
      playerScale, playerScale,
      -M_PI/2, 0);
    }
  }

  activePlayerSize = activePlayer()->get_hand()->get_cards().size();
  for (int i = 0; i < activePlayerSize; i++)  {
    try {
      al_draw_scaled_bitmap(activePlayer()->get_hand()->get_cards().at(i)->get_sprite(),
        0, 0,                                // source origin
        cardWidth, cardHeight,
        (al_get_display_width(al_get_current_display())/2) - (50 * activePlayerSize) + (100 * i), al_get_display_height(al_get_current_display()) - 182,                                // target origin
        130, 182 ,                                // target dimensions
        0                                    // flags
      );
    } catch (std::exception &e) {
      al_draw_scaled_bitmap(cardBack,
        0, 0,                                // source origin
        cardWidth, cardHeight,
        (al_get_display_width(al_get_current_display())/2) - (50 * activePlayerSize) + (100 * i), al_get_display_height(al_get_current_display()) - 182,                                // target origin
        130, 182 ,                                // target dimensions
        0
      );
    }
  }
}

int main() {
    al_init();
    al_install_keyboard();
    al_install_mouse();
    al_init_image_addon();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(16);

    loadSprites();

    timer = al_create_timer(1.0 / 30.0);
    queue = al_create_event_queue();
    disp = al_create_display(1200, 900);
    font = al_create_builtin_font();

    cardBack = al_load_bitmap("sprites/cardback.bmp");
    backGround = al_load_bitmap("sprites/backGround.bmp");
    colorSelect = al_load_bitmap("sprites/colorSelect.bmp");
    colorSelectB = al_load_bitmap("sprites/colorSelectBlue.bmp");
    colorSelectY = al_load_bitmap("sprites/colorSelectYellow.bmp");
    colorSelectG = al_load_bitmap("sprites/colorSelectGreen.bmp");
    colorSelectR = al_load_bitmap("sprites/colorSelectRed.bmp");
    colorSelectCurrent = colorSelect;
    mainMenu = al_load_bitmap("sprites/mainMenu.bmp");
    drawButton = al_load_bitmap("sprites/drawButton.bmp");
    passButton = al_load_bitmap("sprites/passButton.bmp");
    playButton = al_load_bitmap("sprites/playButton.bmp");
    unoButton = al_load_bitmap("sprites/unoButton.bmp");

    ALLEGRO_SAMPLE* cardSlide = al_load_sample("audio/cardSlide.wav");
    ALLEGRO_SAMPLE* colorSelectAudio = al_load_sample("audio/colorSelect.wav");

    int displayWidth =  al_get_display_width(al_get_current_display());
    int displayHeight =  al_get_display_height(al_get_current_display());
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer);

    std::string command = "start";

    ALLEGRO_MOUSE_STATE state;

    while(1)
    {
        al_wait_for_event(queue, &event);
        al_get_mouse_state(&state);
        if(event.type == ALLEGRO_EVENT_TIMER){
          if (game.isPickingColor()) {
            colorSelectCurrent = colorSelect;
            if (state.x > displayWidth/2 && state.x < displayWidth/2 + 200) {
              if (state.y > displayHeight/2 && state.y < displayHeight/2 + 200) {
                colorSelectCurrent = colorSelectR;
              }
              if(state.y < displayHeight/2 && state.y > displayHeight/2 - 200) {
                colorSelectCurrent = colorSelectY;
              }
            }
            if (state.x < displayWidth/2 && state.x > displayWidth/2 - 200) {
              if (state.y > displayHeight/2 && state.y < displayHeight/2 + 200) {
                colorSelectCurrent = colorSelectB;
              }
              if(state.y < displayHeight/2 && state.y > displayHeight/2 - 200) {
                colorSelectCurrent = colorSelectG;
              }
            }
          }
          redraw = true;
        } else if ((event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)) {
          al_destroy_font(font);
          al_destroy_display(disp);
          al_destroy_timer(timer);
          al_destroy_event_queue(queue);
          al_destroy_bitmap(cardBack);
          al_destroy_sample(cardSlide);
          return 0;
        } else if(event.type == ALLEGRO_EVENT_KEY_DOWN){
           while (1) {
            std::cout << "input command: \n";
            std::getline(std::cin,command);
            if (command.compare("end") == 0) {
              break;
            }
            if (command.compare("-showhand") == 0) {
              int playerID = 0;
              std::cout << "insert player:" << std::endl;
              std::cin >> playerID;
              for(int i = 0; i < game.get_playerList().at(playerID)->get_hand()->get_cards().size(); i++) {
                std::cout << game.get_playerList().at(playerID)->get_hand()->get_cards().at(i)->get_name() << ' ';
              }
              std::cout << std::endl;
            }
            if (command.compare("-exit") == 0) {
              al_destroy_font(font);
              al_destroy_display(disp);
              al_destroy_timer(timer);
              al_destroy_event_queue(queue);
              al_destroy_bitmap(cardBack);
              al_destroy_sample(cardSlide);
              return 0;
            }
            if (command.compare("-drawcards") == 0) {
              int playerID = 0;
              int cardNumber = 0;
              std::cout << "insert player:" << std::endl;
              std::cin >> playerID;
              std::cout << "insert card number:" << std::endl;
              std::cin >> cardNumber;
              game.get_playerList().at(playerID)->get_hand()->draw(cardNumber);
              loadSprites();
            }
            if (command.compare("-playcard") == 0) {
              int card;
              while (1) {
                std::cout << "insert card: \n";
                std::cin >> card;
                if (activePlayer()->get_hand()->get_cards().at(card)->isPlayable()) {
                  activePlayer()->get_hand()->play(card);
                  loadSprites();
                  break;
                }
              }
            }
          }
          redraw = true;
        } else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            if (game.isMenuMode()) {
              if (state.x > 700 && state.x < displayWidth && state.y > 250 && state.y < 330) {
                //startGame();
                game.set_MenuMode(false);
              }
              if (state.x > 700 && state.x < displayWidth && state.y > 627 && state.y < 730) {
                al_destroy_font(font);
                al_destroy_display(disp);
                al_destroy_timer(timer);
                al_destroy_event_queue(queue);
                al_destroy_bitmap(cardBack);
                al_destroy_sample(cardSlide);
                return 0;
              }
            } else if (game.isPickingColor()) {
              if (state.x > displayWidth/2 && state.x < displayWidth/2 + 200) {
                if (state.y > displayHeight/2 && state.y < displayHeight/2 + 200) {
                  game.pickedColor("red");
                  al_play_sample(colorSelectAudio, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                }
                if(state.y < displayHeight/2 && state.y > displayHeight/2 - 200) {
                  game.pickedColor("yellow");
                  al_play_sample(colorSelectAudio, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                }
              }
              if (state.x < displayWidth/2 && state.x > displayWidth/2 - 200) {
                if (state.y > displayHeight/2 && state.y < displayHeight/2 + 200) {
                  game.pickedColor("blue");
                  al_play_sample(colorSelectAudio, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                }
                if(state.y < displayHeight/2 && state.y > displayHeight/2 - 200) {
                  game.pickedColor("green");
                  al_play_sample(colorSelectAudio, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                }
              }
            } else if (game.isDrawMode() ) {
              if (state.x > displayWidth - 200 && state.x < displayWidth - 100 && state.y > displayHeight - 200 && state.y < displayHeight - 100) {
                game.drawButtonPressed();
                loadSprites();
              }
            } else if (game.isPassMode() ) {
              if (state.x > displayWidth - 200 && state.x < displayWidth - 100 && state.y > displayHeight - 200 && state.y < displayHeight - 100) {
                game.passButtonPressed();
              }
            } else if (game.isPlayMode() ) {
              if (state.x > displayWidth - 200 && state.x < displayWidth - 100 && state.y > displayHeight - 200 && state.y < displayHeight - 100) {
                game.playButtonPressed();
                loadSprites();
              }
            } else if (activePlayer()->get_unoButton()) {
              if (state.x > displayWidth - 200 && state.x < displayWidth - 100 && state.y > displayHeight - 200 && state.y < displayHeight - 100) {
                activePlayer()->unoPressed();
              }
            } else if (ClickedCard() != -1) {
              if (activePlayer()->get_hand()->get_cards().at(ClickedCard())->isPlayable()) {
                activePlayer()->get_hand()->play(ClickedCard());
                al_play_sample(cardSlide, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                loadSprites();
              }
            }
          redraw = true;
        }

        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            if (game.isMenuMode()) {
              al_draw_scaled_bitmap(mainMenu,
                0, 0,                                // source origin
                1920, 1080,
                0, 0,                   // target origin
                displayWidth, displayHeight,                        // target dimensions
                0                                    // flags
              );
            } else {
              drawFour(false);
              al_draw_scaled_bitmap(cardBack,
                0, 0,                                // source origin
                130, 182,
                (al_get_display_width(al_get_current_display()) * 0.2), al_get_display_height(al_get_current_display()) * 0.2,                                // target origin
                130 * 0.75, 182 * 0.75,                                // target dimensions
                0                                    // flags
              );

              al_draw_scaled_bitmap(game.get_board()->get_stack()->get_cards().back()->get_sprite(),
                0, 0,                                // source origin
                130, 182,
                (al_get_display_width(al_get_current_display())/2) - 65, al_get_display_height(al_get_current_display())/2 - 91,                                // target origin
                130, 182 ,                                // target dimensions
                0                                    // flags
              );

              if (game.isPickingColor()) {
                al_draw_scaled_bitmap(colorSelectCurrent,
                  0, 0,                                // source origin
                  800, 800,
                  displayWidth/2 - 200, displayHeight/2 - 200,                           // target origin
                  400, 400 ,                                // target dimensions
                  0
                );
              }
              if (game.isDrawMode()) {
                al_draw_scaled_bitmap(drawButton,
                  0, 0,                                // source origin
                  400, 160,
                  displayWidth - 200, displayHeight - 200,                            // target origin
                  100, 40,                                // target dimensions
                  0
                );
              }
              if (game.isPassMode()) {
                al_draw_scaled_bitmap(passButton,
                  0, 0,                                // source origin
                  400, 160,
                  displayWidth - 200, displayHeight - 200,                            // target origin
                  100, 40,                                // target dimensions
                  0
                );
              }
              if (game.isPlayMode()) {
                al_draw_scaled_bitmap(playButton,
                  0, 0,                                // source origin
                  400, 160,
                  displayWidth - 200, displayHeight - 200,                           // target origin
                  100, 40,                                // target dimensions
                  0
                );
              }
              if (activePlayer()->get_unoButton()) {
                al_draw_scaled_bitmap(unoButton,
                  0, 0,                                // source origin
                  400, 100,
                  displayWidth - 200, displayHeight - 200,                           // target origin
                  100, 40,                                // target dimensions
                  0
                );
              }
            }

            ALLEGRO_MOUSE_STATE state1;
            al_get_mouse_state(&state1);

            al_flip_display();

            redraw = false;
        }
    }
}
