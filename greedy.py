import cs50

def main():
    while True:
        print("Total change owed is :")
        change = cs50.get_float()
        if change >= 0:
            break
    
    coins = 0
    cents = int(round(change * 100))
    
    coins=coins + cents // 25
    cents =cents % 25
    
    coins=coins + cents // 10
    cents =cents % 10
    
    coins=coins + cents // 5
    cents =cents % 5
    
    coins=coins + cents
    
    print("{}".format(coins))
    
if __name__ == "__main__":
    main()