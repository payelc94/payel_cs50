import cs50
import sys

def main():
    if len(sys.argv) != 2:
        print("You should provide cmd line arguments!")
        exit(1)
    
    key = int(sys.argv[1])
    print("enter the string")
    plain = cs50.get_string()
    cipher = []
    for i in plain:
        if i.isalpha():
             cipher.append(caesar(i, key))     
        else:
            cipher.append(i)
                
    print("".join(cipher))
    exit(0)

def caesar(c, key):
    if c.islower():
        return chr(((ord(c) - 97 + key) % 26) + 97)
    else:
        return chr(((ord(c) - 65 + key) % 26) + 65)
        
if __name__ == "__main__":
    main()