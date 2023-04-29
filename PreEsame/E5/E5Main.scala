object E5Main extends App {
	print("Inserire numero a: ")
	var a = scala.io.StdIn.readDouble()
	print("Inserire numero b: ")
	var b = scala.io.StdIn.readDouble()
	if(a > b) {
		println("a deve essere minore uguale di b")
	}else {
		println(E5.concatena(_ + 1,_ * 2,_ - 1,a,b)(10))	
	}	
}
