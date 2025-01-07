def main():
    x, y = map(int, input().split())
    z, w = map(int, input().split())

    res = ""
    while x != 1 or y != 0 or z != 0 or w != 1:
        if (x > y) :
            res = "0" + res
            x -= y
            z -= w
        
        else:
            res = "1" + res
            y -= x
            w -= z
    print(res)
        
    

if __name__ == "__main__":
    main()