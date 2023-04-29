object E2Main extends App {
	val incrementaDueVolte = E2.applicaDueVolte(x => x+1) _
	val y = incrementaDueVolte(10)
	println(y)
}
