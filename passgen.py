import random
import string

def generate_password(length):
    if length < 4:  
        raise ValueError("Password length must be at least 4 characters")

    
    lowercase = string.ascii_lowercase
    uppercase = string.ascii_uppercase
    digits = string.digits
    punctuation = string.punctuation

   
    password = [
        random.choice(lowercase),
        random.choice(uppercase),
        random.choice(digits),
        random.choice(punctuation)
    ]

   
    all_chars = lowercase + uppercase + digits + punctuation
    password += random.choices(all_chars, k=length-4)

   
    random.shuffle(password)

  
    return ''.join(password)

def main():
    try:
        length = int(input("Enter the desired password length (minimum 4): "))
        password = generate_password(length)
        print(f"Generated Password: {password}")
    except ValueError as e:
        print(e)

if __name__ == "__main__":
    main()
