#ifndef __EXCEPTIONS__
#define __EXCEPTIONS__

class NoUser : public std::exception {
public:
    const char* what() {
        return "User not joined\n";
    }
};

class NoGame : public std::exception {
public:
    const char* what() {
        return "No game created\n";
    }
};

class NoRole : public std::exception {
public:
    const char* what() {
        return "One or more players do not have a role\n";
    }
};

class GameStarted : public std::exception {
public:
    const char* what() {
        return "Game has already started\n";
    }
};

class DeadVotee : public std::exception {
public:
    const char* what() {
        return "Votee is already dead\n";
    }
};

class CannotWakeup : public std::exception {
public:
    const char* what() {
        return "User can not wake up during night\n";
    }
};

class DeadUser : public std::exception {
public:
    const char* what() {
        return "User is dead\n";
    }
};

#endif