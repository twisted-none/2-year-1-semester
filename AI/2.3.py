x = int(input("Enter X: "))

if x < -5:
    print("X in (-infinity, -5)")
elif x > 5:
    print("X in (5, infinity)")
else:
    print("X in [-5, 5]")