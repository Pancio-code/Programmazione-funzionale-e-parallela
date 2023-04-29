object E6Main extends App {
	print("Inserire un intero a: ")
	var a = scala.io.StdIn.readInt()
	print("Inserire un intero b: ")
	var b = scala.io.StdIn.readInt()
	if(a > b) println(E6.equalInRange(_ + 1, _ + (2-1),b,a))
	else println(E6.equalInRange(_ + 1, _ +(2-1),a,b))
}
