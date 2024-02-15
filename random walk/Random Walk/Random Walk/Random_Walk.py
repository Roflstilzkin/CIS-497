
import random
#pizza .7 chance to re-order itself, .2 chance to get donut next, .1 chance for salad
#donut .3 chance to re-order itself, .7 chance to get pizza next
#salad .2 chance to re-order itself, .8 chance to get pizza next
#Question 1: generate a sequence of 20 days worth of orders
#Question 2: what is the probability of each food item?

#initialize starting point at random
start = random.randrange(1,4)
orders = []

p = 0 #represents times pizza picked
d = 0 #represents times donut picked
s = 0 #represents times salad picked

#how many 'days' to run the loop
limit = 20

#starts at day 1
days = 1
while days <= limit:
    #print (days)
    #print (start)
    
    choice = random.randrange(1,11) #random probability selected
    if start == 1:# one (1) will represent choice of pizza    
        if (choice <= 10 and choice >= 4): # 70% chance of happnening
            orders.append('pizza')
            nextchoice = 1
            p += 1
            
        elif (choice <= 3 and choice >= 2):# 20% chance of happening
            orders.append('donut')
            nextchoice = 2
            d += 1

        elif choice == 1: # 10% chance of happening
            orders.append('salad') 
            nextchoice = 3
            s += 1


    if start == 2: #two (2) will represent choice of donut
        if (choice <= 10 and choice >= 4): # 70%chance of happening
            orders.append('pizza')
            nextchoice = 1
            p += 1
 
        elif (choice <= 3 and choice >= 1):# 30% chance of happneing
            orders.append('donut')
            nextchoice = 2
            d += 1

                
    if start == 3: #three (3) will represent choice of salad
        if (choice <= 10 and choice >= 3): # 80% chance of happening
            orders.append('pizza')
            nextchoice = 1
            p += 1

        elif (choice <= 2 and choice >= 1): # 20% chance of happening
            orders.append('salad') 
            nextchoice = 3
            s += 1

    start = nextchoice
    #increments days
    days += 1
#end while

pizzapercent = (p/limit)*100 #calculates the probability of this choice in this iteration
donutpercent = (d/limit)*100 #calculates the probability of this choice in this iteration
saladpercent = (s/limit)*100 #calculates the probability of this choice in this iteration

print (pizzapercent, " Pizza percentage")
print (donutpercent, " Donut percentage")
print (saladpercent, " Salad percentage")