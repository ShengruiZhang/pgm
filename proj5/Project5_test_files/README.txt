input1: small file for debug
>> sna input1.txt EU_Commission output1.txt

input2: large file for timeout test
>> sna input2.txt trevor_r_ output2.txt

input3: the userName has a following cycle
>> sna input3.txt MailChimp output3.txt

input4: all qualified user has the same in-degree centrality 
>> sna input4.txt michaeljhardy output4.txt

input5: userName exists, but no qualified followings
>> sna input5.txt Ehickioya output5.txt

input6: sort by in-degree centrality, no tie 
>> sna input6.txt Awkward_Vic output6.txt

input7: mix case
>> sna input7.txt abiy_atom output7.txt

input8: mix case
>> sna input8.txt Bcum_Brandon output8.txt

input9: invalid input in one line
>> sna input9.txt Poweraidus output9.txt

input10: userName not exists in the graph
>> sna input10.txt ECE275 output10.txt