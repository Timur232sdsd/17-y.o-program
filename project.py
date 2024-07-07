from ipaddress import *
for a in range(16,25):
        net = ip_network(f'134.97.250.117/{a}',0)
        f =1
        for ip in net:
            b = f'{ip:b}'
            if(b[:16].count('0')<b[16:].count('0')):
                  f = 0
        if(f==1):
              print(bin(a))