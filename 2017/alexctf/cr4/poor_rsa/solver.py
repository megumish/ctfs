#https://pequalsnp-team.github.io/writeups/CR3
#https://pequalsnp-team.github.io/writeups/CR4
from crypto_commons.rsa.rsa_commons import *
from crypto_commons.generic import *
from Crypto.PublicKey import RSA

p = long(863653476616376575308866344984576466644942572246900013156919)
q = long(965445304326998194798282228842484732438457170595999523426901)
e = long(65537)
c = open('./flag.b64').read().decode('base64')

fi = lcm(p - 1, q - 1)
d = modinv(e, fi)

key = RSA.construct((p * q, e, d))
print(key.decrypt(c))
