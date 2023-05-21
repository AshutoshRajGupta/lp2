import nltk
from nltk.chat.util import Chat, reflections
import random

pairs = [
    [
        r"my name is (.*)",
        ["Hello %1, How are you today?"]
    ],
    [
        r"hi|hey|hello",
        ["Hello", "Hey there", "Hi, how can I assist you?"]
    ],
    [
        r"what is your name?",
        ["You can call me Chatbot."]
    ],
    [
        r"how are you ?",
        ["I'm good, thanks. How about you?"]
    ],
    [
        r"fine|good|great",
        ["That's wonderful to hear!", "Glad to know you're doing well."]
    ],
    [
        r"not\s?(.*)\s?good",
        ["I'm sorry to hear that. Can I help you with something?"]
    ],
    [
        r"tell me a joke",
        ["Why don't scientists trust atoms? Because they make up everything!"]
    ],
    [
        r"(.*) (movie|book|song) recommendation",
        ["I recommend you check out 'The Shawshank Redemption'. It's a great film!"]
    ],
    [
        r"do you like (movie|book|song)s?",
        ["I don't have personal preferences as I am a chatbot, but I can recommend some if you'd like!"]
    ],
    [
        r"what can you do\??",
        ["I can assist you with general information, provide recommendations, tell jokes, and more. Feel free to ask me anything!"]
    ],
    [
        r"flip a coin",
        ["Sure! It's... %s." % random.choice(["Heads", "Tails"])]
    ],
    [
        r"roll a dice",
        ["Certainly! You rolled a %s." % random.randint(1, 6)]
    ],
    
    [
        r"thank you|thanks",
        ["You're welcome!", "No problem. Happy to help!"]
    ],
    [
        r"how old are you?",
        ["I am a computer program, so I don't have an age."]
    ],
]

chatbot = Chat(pairs, reflections)

print("Welcome to the chatbot. Type 'bye' to exit.")
chatbot.converse()
