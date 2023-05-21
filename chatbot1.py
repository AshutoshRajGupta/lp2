responses = {
    "hello": "Hello!",
    "how are you?": "I'm good, thank you!",
    "what is your name?": "My name is ChatBot.",
    "bye": "Goodbye!"
}

def chat():
    while True:
        user_input = input("User: ")
        user_input = user_input.lower()

        if user_input in responses:
            print("ChatBot:", responses[user_input])
        else:
            print("ChatBot: I'm sorry, I don't understand.")

        if user_input == "bye":
            break

chat()



