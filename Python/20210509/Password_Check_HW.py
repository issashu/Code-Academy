from string import ascii_lowercase, ascii_uppercase, digits

class PasswordPolicy:
    lowercase = ascii_lowercase
    upper = ascii_uppercase
    digits = digits
    characters = ["$#@"]
    lowerLetters = 2
    upperLetters = 1
    numberCount = 3
    character = 1
    minLength = 8
    maxLength = 15
    
    def __init__(self):
        pass
    def CheckPassword(self, parola):
        if len(parola) < self.minLength or len(parola) > self.maxLength:
            return False
        elif parola.count(self.lowercase) < self.lowerLetters or parola.count(self.upper) < self.upperLetters \
            or parola.count(self.digits) < self.numberCount or not any((c in self.characters) for c in parola):
            return False
        else:
            return True

#Here comes password input check:

PassPolicy = PasswordPolicy()
paroli = []

passChecks = input("How many passwords do you want to check : ")
for i in range(int(passChecks)):
    paroli.append(input("Please enter a password to check: "))

for i in range(int(passChecks)):
    if PassPolicy.CheckPassword(paroli[i]):
        print("{} meet the current password policy".format(paroli[i]))
    else:
        print("{} does not pass the security requirements!".format(paroli[i]))