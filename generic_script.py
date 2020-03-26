#!/usr/bin/env python3

import sys

g = open(sys.argv[1][0: len(sys.argv[1]) - 4] + "txt", "w+")

##############
#Premier data#
##############

f1 = open(sys.argv[1], "r")

le_numero_de_la_ligne_de_la_data1 = ?????

for i in range(le_numero_de_la_ligne_de_la_data1):
    line1 = f1.readline()

line1 = line1[17:len(line1) - 3]
print(line1)
liste1 = line1.split(", ")

###############################
#Deuxieme data#


f2 = open(sys.argv[1], "r")

le_numero_de_la_ligne_de_la_data2 = ?????

for i in range(le_numero_de_la_ligne_de_la_data2):
    line2 = f2.readline()

line2 = line2[17:len(line2) - 3]
print(line2)
liste2 = line2.split(", ")


###################
# SI il y a plus de data

####f3 = open(sys.argv[1], "r")
####
####le_numero_de_la_ligne_de_la_data3 = ???
####
####for i in range(le_numero_de_la_ligne_de_la_data3):
####    line3 = f3.readline()
####
####line3 = line3[17:len(line3) - 3]
####print(line3)
####liste3 = line3.split(", ")


rentrer_la_hauteur_le_y_en_gros = ????
rentrer_la_largeur_le_x_en_gros = ????

a = 0
for y in range(rentrer_la_hauteur_le_y_en_gros):
    for j in range(rentrer_la_largeur_le_x_en_gros):
        if (int(liste2[a]) != 0): # rajoute int(liste3[a]) != 0 si il y a d'autres datas
            g.write("1")
        else:
            g.write("0")
        a = a + 1
    g.write("\n")


f1.close()
f2.close()
g.close()