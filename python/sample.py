class sample:
    def __init__(self):
        print("sample ctor")
    def add(self,a,b):
        return a+b
    def __del__(self):
        print('sample dtor')

a = input().split(",")
print(a)


