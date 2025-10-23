ctype Tree where
      Lf: Int -> Tree
      Br: Int -> Tree -> Tree ->Tree

root = Br.1.(Br.2.(Lf.4).(Lf.5)).(Lf.3)

inorder: Tree -> [Int]
inorder.(Lf.x) = [x]
inorder.(Br.n.lt.rt) =inorder.lt ++[n] ++ inorder.rt


mirror: Tree -> Tree
mirror.(Lf.x) = Lf.x
mirror.(Br.n.lt.rt) = Br.n. rt.lt