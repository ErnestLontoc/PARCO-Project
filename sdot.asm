; Ernest James Lontoc S11
section .text
default rel
bits 64
global sdotasm

sdotasm:
   push     rbp
   mov      rbp, rsp
   add      rbp, 16

   mov      r12, rdx   
   mov      r13, r8    
   xor      r15, r15   

   Loop:
        cmp     rcx, 0       
        jle     Exit  

        mov     r14, qword [r12]  
        imul    r14, qword [r13]  
        add     r15, r14        

        add     r12, 8     ; 8 because long long int is 64bit
        add     r13, 8      

        sub     rcx, 1           
        jmp     Loop  

   Exit:
        mov     rax, r15   
        pop     rbp              
        ret                     