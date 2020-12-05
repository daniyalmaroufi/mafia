#ifndef __EXCEPTIONS__
#define __EXCEPTIONS__

class NoUser : public std::exception {
public:
    const char* what() {
        return "User not joined";
    }
};

class NoGame : public std::exception {
public:
    const char* what() {
        return "No game created";
    }
};

class NoRole : public std::exception {
public:
    const char* what() {
        return "One or more players do not have a role";
    }
};

class GameStarted : public std::exception {
public:
    const char* what() {
        return "Game has already started";
    }
};

#endif