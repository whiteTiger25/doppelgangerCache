/*BEGIN_LEGAL 
Intel Open Source License 

Copyright (c) 2002-2015 Intel Corporation. All rights reserved.
 
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.  Redistributions
in binary form must reproduce the above copyright notice, this list of
conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.  Neither the name of
the Intel Corporation nor the names of its contributors may be used to
endorse or promote products derived from this software without
specific prior written permission.
 
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE INTEL OR
ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
END_LEGAL */
/*

compare 64 bit value od edx:eax with the destination memory operand.
  if ==
     store ecx:ebx in the destination memory operand and zf=1
  if !=
     store load the destination memory operand into edx:eax and zf=0

This test checks that the correct memory location is referenced when ebx is
explicitly used in the memory operand of the cmpxchg8b instruction.


*/


int cmpxchg8_with_explicit_ebx();

unsigned int eaxVal;
unsigned int edxVal;
unsigned char a[] = {0x1, 0xff, 0xff, 0xff, 0x2, 0xff, 0xff, 0xff};
int main()
{
    
    cmpxchg8_with_explicit_ebx();
    printf ("eaxVal %x edxVal %x\n", eaxVal, edxVal);
    /*
    asm( "mov %ebp, %ebx");
    asm( "mov $8, %eax");
    asm( "cmpxchg8b 0x0(%ebx,%eax,1)");
    */
}
