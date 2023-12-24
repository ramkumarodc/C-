#include <iostream>
#include <string>

// Handler interface
class Handler {
public:
    virtual void handleRequest(const std::string& request) = 0;
    virtual void setNextHandler(Handler* nextHandler) = 0;
};

// Concrete handler
class ConcreteHandler : public Handler {
private:
    Handler* nextHandler;

public:
    ConcreteHandler() : nextHandler(nullptr) {}

    void handleRequest(const std::string& request) override {
        if (canHandle(request)) {
            std::cout << "ConcreteHandler handles the request: " << request << std::endl;
        } else if (nextHandler) {
            std::cout << "Passing the request to the next handler..." << std::endl;
            nextHandler->handleRequest(request);
        } else {
            std::cout << "No handler can process the request." << std::endl;
        }
    }

    void setNextHandler(Handler* nextHandler) override {
        this->nextHandler = nextHandler;
    }

    bool canHandle(const std::string& request) {
        // Implement your specific logic for handling the request
        return request == "specificRequest";
    }
};

int main() {
    // Create concrete handlers
    ConcreteHandler handler1;
    ConcreteHandler handler2;
    ConcreteHandler handler3;

    // Set up the chain
    handler1.setNextHandler(&handler2);
    handler2.setNextHandler(&handler3);

    // Process requests
    handler1.handleRequest("genericRequest");
    handler1.handleRequest("specificRequest");
    handler1.handleRequest("otherRequest");

    return 0;
}
