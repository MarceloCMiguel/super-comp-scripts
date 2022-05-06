import random
import numpy as np
n_max = 200
m = 1
for n in np.arange(5,n_max+1,1):
     cap_max = random.randint(n//2,n*2)
     lista_obj = []
     for i in range(n):
          peso = random.randint(1,int(cap_max*1.5))
          valor = random.randint(1,int(cap_max*3))
          obj = {'peso':peso,'valor':valor}
          lista_obj.append(obj)
     random.shuffle(lista_obj)
     valores = ""
     for i in lista_obj:
          valores+= str(i['peso']) + " " + str(i['valor']) + '\n'
     resultado = str(n) + " " + str(peso) + '\n' + valores
     file = f'in{m}.txt'
     f = open(file,'w')
     f.writelines(resultado)
     f.close()
     m+=1
# n = 10 # tamanho da primeira sequência
# m = 40 # tamanho da segunda sequência
# file = 'dna.seq' # nome do arquivo a ser gerado
# f = open(file, 'w')
# seq=[str(n)+'\n',
#      str(m)+'\n',
#      ''.join(random.choices(['A','T','C','G','-'],k=n))+'\n',
#      ''.join(random.choices(['A','T','C','G','-'],k=m))]
# f.writelines(seq)
# f.close()
# print(''.join(seq))