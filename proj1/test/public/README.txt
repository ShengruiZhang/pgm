==== Command Line Arguments and Input Files for Public Test Cases ====

test1 - Some nearby business, but only one good (only one nearby business has minAvgRating=5.00)
>> ./spork test1.txt output1.txt 40.41 -80.00 0.07 5.00

test2 - Some good businesses, but none nearby
>> ./spork test2.txt output2.txt 35.56 -100 0.00 1.00

test3 - userLoc has negative coordinates (e.g., user is southwest of the origin)
>> ./spork test3.txt output3.txt -35.09 -80.83 4.00 2.00

test4 - Business with maximum adLevel is last in list (and there are no ties)
>> ./spork test4.txt output4.txt 35.15 -80.85 0.50 4.50
