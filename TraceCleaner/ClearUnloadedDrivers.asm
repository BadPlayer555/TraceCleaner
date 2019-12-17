ClearUnloadedDrivers proc
 
	mov rdx, 1000h
	mov rax, 74D2854DC98B4C00h
Scan:
	cmp [rcx+rdx], rax
	je Found
	inc rdx
	cmp rdx, 250000h
	jl Scan
	mov rax, 0
	ret
Found:
	mov qword ptr [rcx+rdx],0
	mov qword ptr [rcx+rdx-8],0
	mov rax, 1
	ret
 
ClearUnloadedDrivers endp