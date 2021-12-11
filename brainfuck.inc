
#if defined _INC_Brainfuck
    #endinput
#endif

#define _INC_Brainfuck

#if !defined BF_MEMORY_SIZE
    #define BF_MEMORY_SIZE                  (30_000)
#endif

new 
    mem[BF_MEMORY_SIZE];

stock BF_Interpret(output[], const input[], len = sizeof(output))
{
    new
        memPos = 0, 
        outPos = 0;
    
    for (new i = 0; input[i] != EOS; i ++)
    {
        switch (input[i])
        {
            case '>': {
                memPos ++;    
            }
            case '+': {
                mem[memPos] ++;
            }
            case '<': {
                memPos --;
            }
            case '-': {
                mem[memPos] --;
            }
            case '.': {

                if (outPos > len)
                {
                    printf("[ERROR] Brainfuck code exceeding output length (bf length: %d | output length: %d).", outPos, len);
                    return 0;
                }

                output[outPos] = mem[memPos];
                outPos++;
            }
            case '[': {
                new nestedLoops = 1;

                if (mem[memPos] == '\0')
                {
                    do
                    {
                        i++;
                        if (input[i] == '[')
                        {
                            nestedLoops++;
                        }
                        else if (input[i] == ']')
                        {
                            nestedLoops--;
                        }
                    } while (nestedLoops != 0);
                }
            }
            case ']': {
                new nestedLoops = 0;
                do
                {
                    if (input[i] == '[')
                    {
                        nestedLoops ++;
                    }
                    else if (input[i] == ']')
                    {
                        nestedLoops --;
                    }
                    i --;
                } while (nestedLoops != 0);
            }
        }
    }
    return 1;
}

