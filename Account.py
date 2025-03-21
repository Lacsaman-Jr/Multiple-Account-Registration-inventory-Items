print ("Welcome to the Account System")
from shop import shop
account_name, Password = ('', '')

def register():
    global Password
    global account_name
    account_name = input ("Account Name:\t")
    Password = input("Password:\t")
    print(f"Registered with Account Name: {account_name} and Password: {Password}")

register()

attempts = 0
while attempts < 3:
    acc_name = input("Enter your email:\t")
    acc_pass = input("Enter your password:\t")

    if acc_pass == Password and account_name == acc_name:
        print ("success\n\n\n")
        while True:
            shop()
            choice = input("Do you want to shop again? (y/n): ")
            if choice == 'n':
                print ("Thank you for shopping with us!")
            break
        break
    else:
        print("unsuccessful")
        attempts += 1
else:
    print("Too many unsuccessful attempts")