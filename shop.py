def shop():
    print("Welcome to the shop!")
    product = {"apple": 10, "banana": 20, "orange": 30, "grapes": 40, "mango": 50}
    money = 10000
    print(f'You have {money} Pesos in your wallet')
    print('Available products are: ')

    for key, value in product.items():
        print(f'{key} price is {value} Pesos')

    item = input("what do you want to buy: ").lower()
    quantity = int(input(f'How many {item} do you want to buy: '))
    bill = product[item] * quantity
    print(f'Your total bill is {bill} Pesos')
    if bill > money:
        print('Insufficient balance')
    else:
        money -= bill
        print(f'You have {money} Pesos left in your wallet')