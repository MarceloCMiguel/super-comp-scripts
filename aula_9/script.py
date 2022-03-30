import subprocess
import time
lista_program = ['../aula_5/main','../aula_6/main','../busca_local/main']
for i in range(1,8):

    with open(f'in{i}.txt') as f:

        start = time.perf_counter()
        proc = subprocess.run(['../aula_5/main'], input=f.read(), text=True, capture_output=True)
        end = time.perf_counter()

        print('Saída:', proc.stdout)
        print('Stderr:', proc.stderr)
        print('Tempo total(s):', end - start)
