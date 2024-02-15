
import random
#pizza .7 chance to re-order itself, .2 chance to get donut next, .1 chance for salad
#donut .3 chance to re-order itself, .7 chance to get pizza next
#salad .2 chance to re-order itself, .8 chance to get pizza next
#Question 1: generate a sequence of 20 days worth of orders
#Answer: created a while loop that runs to what ever the limit is set to
######## the orders are stored into the orders[] list

#Question 2: what is the probability of each food item?
#Answer: depends on the specifics of a run, 80/5/15, 85/15/0, 70/30/0, 90/10/0, 60/25/15, 80/10/10, 65/5/30, 75/25/0
 
#initialize starting point at random
start = random.randrange(1,4) #picks a random number between 1 and 3
orders = [] #initializes the list/array

p = 0 #represents times pizza picked
d = 0 #represents times donut picked
s = 0 #represents times salad picked

limit = 20 #how many 'days' to run the loop
days = 1 #starts at day 1

while days <= limit:
    choice = random.randrange(1,11) #random probability selected
    if start == 1:# one (1) will represent choice of pizza    
        if (choice <= 10 and choice >= 4): # 70% chance of happnening
            orders.append('pizza') #add to list
            nextchoice = 1 
            p += 1 #pizza picked increment counter
        elif (choice <= 3 and choice >= 2):# 20% chance of happening
            orders.append('donut') #add to list
            nextchoice = 2
            d += 1 #donut picked, increment counter
        elif choice == 1: # 10% chance of happening
            orders.append('salad') #add to list
            nextchoice = 3
            s += 1 #salad picked increment counter

    if start == 2: #two (2) will represent choice of donut
        if (choice <= 10 and choice >= 4): # 70%chance of happening
            orders.append('pizza') #add to list
            nextchoice = 1
            p += 1 #pizza picked, increment counter
        elif (choice <= 3 and choice >= 1):# 30% chance of happneing
            orders.append('donut') #add to list
            nextchoice = 2
            d += 1 #donut picked, increment counter
            
    if start == 3: #three (3) will represent choice of salad
        if (choice <= 10 and choice >= 3): # 80% chance of happening
            orders.append('pizza') #pizza picked, add to list
            nextchoice = 1
            p += 1 #pizza picked, increment counter
        elif (choice <= 2 and choice >= 1): # 20% chance of happening
            orders.append('salad') #add salad to list
            nextchoice = 3
            s += 1 #salad picked, increment to counter

    start = nextchoice #passes the value to start for the next loop
    days += 1 #increments days
#end while

pizzapercent = (p/limit)*100 #calculates the probability of this choice in this iteration
donutpercent = (d/limit)*100 #calculates the probability of this choice in this iteration
saladpercent = (s/limit)*100 #calculates the probability of this choice in this iteration
print('Days passed: ', days-1) # print how many days have passed, must subtract 1 because days is incremented at bottom of while loop but the next day wont execute cause of the limit being reached.
print (pizzapercent, " Pizza percentage")
print (donutpercent, " Donut percentage")
print (saladpercent, " Salad percentage")