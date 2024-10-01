#1) Sabe-se que uma lata de tinta tem um custo C e é capaz de pintar uma área de M metros quadrados. 
#Faça um programa que leia a largura L, a altura A de uma parede, o valor C de uma lata de tinta e o rendimento M desta lata. 
#Após isso, imprima quantas latas de tintas são necessárias e o custo total (com duas casas decimais). Assuma que não é possível comprar lata de tinta fracionada.
# import math
# larguraParede = float(input("Digite a largura da parede em metros: "))
# alturaParede = float(input("Digite a altura da parede em metros: "))
# custoLata = float(input("Digite o custo de uma lata de tinta: R$"))
# rendimentoLata = float(input("Digite o rendimento de uma lata de tinta em metros quadrados: "))
# areaParede = larguraParede*alturaParede
# qntdLatas = math.ceil(areaParede / rendimentoLata)
# print(f"Para pintar a parede serão necessárias {qntdLatas} latas de tinta. O custo total será de R${round(custoLata*qntdLatas, 2)}")

#2) Faça um programa que leia um número inteiro S que representa uma quantidade de segundos. 
#Seu programa deve imprimir quatro valores inteiros, que representam a quantidade de segundos *S* em dias, horas, minutos e segundos. 
#Por exemplo, 188365 segundos representam 2 dias, 4 horas, 19 minutos e 25 segundos.
# segundosTotais = int(input("Digite um valor de segundos: "))
# dias = segundosTotais // 86400
# segundosRestantes = segundosTotais % 86400
# horas = segundosRestantes // 3600
# segundosRestantes = segundosRestantes % 3600
# minutos = segundosRestantes // 60
# segundosRestantes = segundosRestantes % 60
# print(f"{segundosTotais} segundos, representam {dias} dias, {horas} horas, {minutos} minutos e {segundosRestantes} segundos")

#3) Faça um programa que leia um número inteiro (assuma que esse número terá 4 dígitos obrigatoriamente) e inverta esse número. 
#Por fim escreva o número invertido. O seu programa deve apenas manipular números inteiros. Não é permitido usar strings, listas, etc.
# numeroInicial = int(input("Digite um número de 4 dígitos: "))
# numero = numeroInicial
# num1 = numero // 1000
# numero -= num1*1000
# num2 = numero // 100
# numero -= num2*100
# num3 =  numero // 10
# numero -= num3*10
# num4 = numero

# print(f"Número normal: {numeroInicial}")
# print(f"Número invertido: {num4}{num3}{num2}{num1}")

#4) Faça um programa que leia dois números inteiros e imprima o maior deles.
# numero1 = int(input("Digite o primeiro número: "))
# numero2 = int(input("Digite o segundo número: "))
# if numero1 > numero2:
#     print(f"{numero1} é o maior")
# elif numero2 > numero1:
#     print(f"{numero2} é o maior")
# else:
#     print("Os números são iguais")

#5) A avenida principal da cidade de Algoritmopolis possui limite de velocidade de *L* km/h. 
#Se o motorista ultrapassar essa velocidade, é aplicado uma multa de R$ *M*, mais R$ *A* por cada km acima do limite. 
#Faça um programa que leia o limite *L*, o valor da multa *M*, o valor adicional *A* e a velocidade *V* captada pelo radar e informe o valor total da multa. 
#Considere *L* e *V* sempre como números inteiros. Apresente a resposta com duas casas decimais
# limiteVelocidade = int(input("Digite o limite de velocidade: "))
# velocidadeCaptada = int(input("Digite a velocidade captada pelo radar: "))
# valorMulta = float(input("Digite o valor da multa: R$"))
# adicionalMulta = float(input("Digite o valor adicional pago por km acima do limite: R$"))

# excessoVelocidade = velocidadeCaptada - limiteVelocidade
# multaTotal = valorMulta + adicionalMulta*excessoVelocidade

# print(f"O valor total pago pela multa é de {round(multaTotal, 2)}")

#6) Faça um algoritmo que leia 2 valores inteiros *A* e *B*. 
#Coloque-os em ordem crescente (ou seja, ao final *A* deve armazenar o menor valor e *B* o maior valor). 
#Utilize o modelo abaixo apresentado no final do exercício, modificando apenas o processamento.
# A = int(input("Digite um valor inteiro: "))
# B = int(input("Digite outro valor inteiro: "))
# print(f"Inicialmente: {A}, {B}")
# if A > B:
#     p = B
#     B = A
#     A = p
# print(f"Ordenado em crescente: {A}, {B}")

#7) Faça um programa que leia três números inteiros *A*, *B* e *C* e imprima o maior deles.
# numero1 = int(input("Digite o primeiro número: "))
# numero2 = int(input("Digite o segundo número: "))
# numero3 = int(input("Digite o terceiro número: "))
# if numero1 > numero2 and numero1 > numero3:
#     print(f"{numero1} é o maior")
# elif numero2 > numero1 and numero2 > numero3:
#     print(f"{numero2} é o maior")
# elif numero3 > numero1 and numero3 > numero2:
#     print(f"{numero3} é o maior")
# else:
#     print("Não tem um número maior")

#8) Faça um algoritmo que leia 3 valores inteiros *A*, *B* e *C*. 
#Coloque-os em ordem crescente (ou seja, ao final *A* deve armazenar o menor valor, *C* o maior e *B* o valor do meio).
valorA = int(input("Digite o primeiro número: "))
valorB = int(input("Digite o segundo número: "))
valorC = int(input("Digite o terceiro número: "))
if valorA < valorB and valorA < valorC:
    if valorB > valorC:
        p = valorC
        valorC = valorB
        valorB = p
elif valorB < valorA and valorB < valorC:
    p = valorA
    valorA = valorB
    valorB = valorA
    if valorB > valorC:
        p = valorC
        valorC = valorB
        valorB = p
#else:
