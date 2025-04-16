def main():
  n, k = map(int, input().split())
  s = input().split('.')
  for i in s:
    if(len(i) >= k):
      print("NO")
      return
  print("YES")

main()