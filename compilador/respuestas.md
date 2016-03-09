1. Escriban qué esperan de cada uno de los pasos

Pre-procesador: Se encarga de incluir headers y definir macros. Reemplaza los "define" por el valor elegido.
Compilación I: Convierte a assembler.
Compilación II: Convierte a lenguaje de máquina (-->ilegible). Con "nm" listo los simbolos de los object files.
Linkeo: linkea a librerías ya sean estáticas o dinámicas.

2. ¿Qué agregó el preprocesador?

Agregó el archivo stdio.h incluído en el encabezado. Si defino alguna constante (por ej, # define PI 3.14), agrega eso al texto de la función.

3. Identificar en la rutina de assembler las funciones

Tengo dos funciones; 
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$11, %esi
	movl	$31, %edi
	call	add_numbers
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	add_numbers
	.type	add_numbers, @function
add_numbers:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-8(%rbp), %eax
	movl	-4(%rbp), %edx
	addl	%edx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc

Que llaman a otras funciones que como por ejemplo en la línea: 	call	add_numbers.
Las dos líneas anteriores guardan en registros los valores de los parámetros de entrada. 

4. Explicar qué quieren decir los símbolos que se crean en el objeto

nm me da el siguiente output:
000000000000003c T add_numbers
0000000000000000 T main
                 U printf

T es texto, son las funciones que definí. U es de indefined pues necesita linkear a alguna librería para reconocer la función.

5. ¿En qué se diferencian los símbolos del objeto y del ejecutable?

El ejecutable tiene más símbolos. Los U que aparecen ahora en realidad "apuntan" a la librería estándar de donde tienen que sacar la función. Además, aparecen los símbolos en mínuscula que son inaccesibles desde afuera. 



