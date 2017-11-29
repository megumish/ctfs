from pwn import *
from hashlib import md5

context.log_level = "debug"
def register(name):
    conn.sendlineafter("Please [r]egister or [l]ogin", "r")
    conn.sendline(name)
    conn.recvuntil("Here is your secret:\n")
    return conn.recvuntil("\n")[:-1]

def login(secret):
    conn.sendlineafter("Please [r]egister or [l]ogin", "l")
    conn.sendline(secret)
    conn.recvuntil("Welcome ")
    return conn.recvuntil("\n")[:-2]

BS = 16
pad = lambda s: s + (BS - len(s) % BS) * chr(BS - len(s) % BS) 
unpad = lambda s : s[0:-ord(s[-1])]

def solve():
    secret = register(md5(pad("admin")).digest() + "admin")
    print(len(secret))
    name = login(secret[32:])
    conn.stream()
    conn.close()
    
if __name__ == "__main__":
    if len(sys.argv) > 1:
        HOST = "localhost"
        PORT = 114242
        conn = remote(HOST, PORT)
    else:
        conn = process("./integrity.py")
    solve()
