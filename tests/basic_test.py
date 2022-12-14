import sys
import subprocess
import os
import pytest

def basic_test(input: str):
    dir = os.path.dirname(__file__)
    path = os.path.join(dir, '../build/src/Debug/tictactoe.exe')
    
    assert os.path.exists(path), 'tictactoe.exe not found!'

    cmd = f'{path}'

    tictactoe = subprocess.Popen(cmd,
                             stdin=subprocess.PIPE,
                             stdout=subprocess.PIPE,
                             stderr=subprocess.PIPE) 
                             
    try:                                
        output, error = tictactoe.communicate(input=input.encode(), timeout=0.5)
    except subprocess.TimeoutExpired:
        tictactoe.kill()
        tictactoe.wait()
        output, error = tictactoe.communicate()
        print(output.decode())
        pytest.fail('TimeoutExpired. See program output for details.')
        
    assert tictactoe.returncode == 0, f'Error in program:\n{output.decode()}\n{error.decode()}'
    
    return output.decode()
        
if __name__ == '__main__':
    print('This basic test script not meant to be run by himself.')