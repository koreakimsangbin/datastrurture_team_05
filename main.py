survey_point = 0
do_survey = 0
freq = 1
eat_existen = 1

korean_style_food = 1
chinese_style_food = 2
western_style_food = 3
taiwan_style_food = 4

if (survey_point != 0):
    do_survey += 1

while (1):
    print(freq, "time to use this program")
    search_food_style = int(
        input("what kind of style food do you need: 1.korean food 2. chinese food 3. western food 4. taiwan food : "))
    if (search_food_style == 1):
        print("korean food")
        eat_existen = int(input("Did you eat it: 1. Yes 2. No : "))
        if (eat_existen == 1):
            print("eat")
            eat_existen += 1
        else:
            print("no eat")


    elif (search_food_style == 2):
        print("chinese food")
        eat_existen = int(input("Did you eat it: 1. Yes 2. No : "))
        if (eat_existen == 1):
            print("eat")
            eat_existen += 1
        else:
            print("no eat")

    elif (search_food_style == 3):
        print("western food")
        eat_existen = int(input("Did you eat it: 1. Yes 2. No : "))
        if (eat_existen == 1):
            print("eat")
            eat_existen += 1
        else:
            print("no eat")

    elif (search_food_style == 4):
        print("taiwan food")
        eat_existen = int(input("Did you eat it: 1. Yes 2. No : "))
        if (eat_existen == 1):
            print("eat")
            eat_existen += 1
        else:
            print("no eat")

    exit_code = int(input("Do you want to exit this progran: 1. Yes 2. No : "))
    if (exit_code == 1):
        break

    else:
        freq += 1


