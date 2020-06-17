value=0
espacios = 40

filepath = 'salida'

casos=["Casos"]
voraz = ["Voraz"]
memoizado = ["Memoizado"]
recursivo = ["Recursivo"]

with open(filepath) as f:
    lines = [line.rstrip() for line in f]


print("-"*195)
print("|"," "*espacios,"Casos"," "*espacios,"|"," "*(17-len("Voraz")),"Voraz"," "*(18-len("Voraz")),"|"," "*(19-len("Memoizado")),"Memoizado"," "*(20-len("Memoizado")),"|"," "*(19-len("Recursivo")),"Recursivo"," "*(20-len("Recursivo")),"|")
ayuda = []
for linea in lines:
    if(value == 0):
        print("-"*195)
        print("|",linea," "*(2*espacios-len(linea)+6),"|",end='')
    if(value == 1):
        ayuda.append(linea)
    if(value >= 2 and value <=4): 
        temp = linea.split()
        print(temp[5]," "*(32-len(temp[5])),"|",end="")
        ayuda.append(temp[9])
    if(value ==4):
        print("")
        print("|",ayuda[0]," "*(2*espacios-len(ayuda[0])+6),"|",ayuda[1]," "*(31-len(ayuda[1])),"|",ayuda[2]," "*(31-len(ayuda[2])),"|",ayuda[3]," "*(31-len(ayuda[3])),"|")
    value+=1
    if(value == 5):
        ayuda.clear()
        value =0

print("-"*195)
    


