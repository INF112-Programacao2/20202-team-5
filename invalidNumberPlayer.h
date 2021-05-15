#ifndef EXCESSO_PLAYER_H_
#define EXCESSO_PLAYER_H_
#include "stdexcept"

class Excesso_player : public std::exception{
    public:
        virtual const char* what() const noexcept override;
};

#endif
