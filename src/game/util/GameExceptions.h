//
// Created by usuario on 19/8/19.
//

#ifndef COLINA_ENGINE_GAMEEXCEPTIONS_H
#define COLINA_ENGINE_GAMEEXCEPTIONS_H

#include <exception>

class LesserException : public std::exception {};

class TooManyWordsException : public LesserException {
    public :
      virtual const char* what() const throw() {
          return "Error: too many words given. Write 2-word commands";
      }
};

class InvalidExamineException : public LesserException {
    public:
       virtual const char* what() const throw() {
           return "Error: the only valid 1-word command is \"examine\"";
       }
};

class UnknownItemException : public LesserException {
    public:
        virtual const char* what() const throw() {
            return "There is no such item in this area";
        }
};

class UnknownActionException : public LesserException {
    public:
        virtual const char* what() const throw() {
            return "I cannot perform this command";
        }
};

class FatalException : public std::exception {};

class FileLoadError : public FatalException {
    public:
        virtual const char* what() const throw() {
            return "Error: error while opening the given game file";
        }
};

class InvalidXMLError : public FatalException {
    public:
        virtual const char* what() const throw() {
            return "Error: invalid XML file";
        }
};

class InvalidAreaError : public FatalException {
    public:
        virtual const char* what() const throw() {
            return "Error: Invalid file: only Area elements can be children of"
                   "the top XML node";
        }
};

class InvalidItemError : public FatalException {
    public:
        virtual const char* what() const throw() {
            return "Error: Invalid file: only Item elements can be children of"
                   "Area elements";
        }
};

class InvalidStateError : public FatalException {
    public:
        virtual const char* what() const throw() {
            return "Error: Invalid file: only State elements can be children of"
                   "Item elements";
        }
};

class InvalidCommandError : public FatalException {
    public:
        virtual const char* what() const throw() {
            return "Error: Invalid file: only Command elements can be children of"
                   "State elements or of the one-word-command list";
        }
};

class InvalidActionError : public FatalException {
    public:
        virtual const char* what() const throw() {
            return "Error: Invalid file: only Action elements can be children of"
                   "Command elements";
        }
};

class XMLQueryError : public FatalException {
    public:
        virtual const char* what() const throw() {
            return "Error: an attribute in the XML has been badly specified";
        }
};

class XMLUnknownActionError : public FatalException {
    public:
        virtual const char* what() const throw() {
            return "Error: unknown action specified in XML";
        }
};

class UnknownLocationError : public FatalException {
    public:
        virtual const char* what() const throw() {
            return "Error: the player has been moved to an unspecified location";
        }
};

class UnknownStateError : public FatalException {
    public:
        virtual const char* what() const throw() {
            return "Error: the item has been set to an unspecified state";
        }
};

class MultipleStartingAreasError : public FatalException {
    public:
        virtual const char* what() const throw() {
            return "Error: multiple starting areas defined";
        }
};

class DuplicatedElementError : public FatalException {
    private:
        std::string elemType;
        std::string elemName;

    public:
        DuplicatedElementError(std::string type, std::string name) {
            elemType = type;
            elemName = name;
        }

        virtual const char* what() const throw() {
            std::string error;
            error = "Error: element of type " + elemType +
                    "has a duplicated element of name " + elemName;

            return error.c_str();
        }
};

class UnknownItemError : public  FatalException {
    public:
        virtual const char* what() const throw() {
            return "Error: trying to access an unexistant item";
        }
};

#endif //COLINA_ENGINE_GAMEEXCEPTIONS_H

