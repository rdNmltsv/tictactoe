from basic_test import *
        
def test_vertical_0():
    result = basic_test('1\n2\n1\n2\n4\n3\n7\nexit\n')
    desired = 'Winner is X!'
    assert result.find(desired) != -1, 'Wrong game result.'

def test_vertical_1():
    result = basic_test('1\n2\n2\n1\n5\n3\n8\nexit\n')
    desired = 'Winner is X!'
    assert result.find(desired) != -1, 'Wrong game result.'
        
def test_vertical_2():
    result = basic_test('1\n2\n3\n1\n6\n2\n9\nexit\n')
    desired = 'Winner is X!'
    assert result.find(desired) != -1, 'Wrong game result.'
        
def test_vertical_3():
    result = basic_test('1\n2\n2\n1\n3\n4\n5\n7\nexit\n')
    desired = 'Winner is O!'
    assert result.find(desired) != -1, 'Wrong game result.'

def test_vertical_4():
    result = basic_test('1\n2\n1\n2\n3\n5\n4\n8\nexit\n')
    desired = 'Winner is O!'
    assert result.find(desired) != -1, 'Wrong game result.'
        
def test_vertical_5():
    result = basic_test('1\n2\n1\n3\n2\n6\n4\n9\nexit\n')
    desired = 'Winner is O!'
    assert result.find(desired) != -1, 'Wrong game result.' 
        
def test_horizontal_0():
    result = basic_test('1\n2\n1\n4\n2\n6\n3\nexit\n')
    desired = 'Winner is X!'
    assert result.find(desired) != -1, 'Wrong game result.'

def test_horizontal_1():
    result = basic_test('1\n2\n4\n1\n5\n3\n6\nexit\n')
    desired = 'Winner is X!'
    assert result.find(desired) != -1, 'Wrong game result.'
        
def test_horizontal_2():
    result = basic_test('1\n2\n7\n1\n8\n2\n9\nexit\n')
    desired = 'Winner is X!'
    assert result.find(desired) != -1, 'Wrong game result.'
        
def test_horizontal_3():
    result = basic_test('1\n2\n1\n4\n3\n5\n8\n6\nexit\n')
    desired = 'Winner is O!'
    assert result.find(desired) != -1, 'Wrong game result.'

def test_horizontal_4():
    result = basic_test('1\n2\n1\n4\n3\n5\n8\n6\nexit\n')
    desired = 'Winner is O!'
    assert result.find(desired) != -1, 'Wrong game result.'
        
def test_horizontal_5():
    result = basic_test('1\n2\n1\n7\n2\n8\n4\n9\nexit\n')
    desired = 'Winner is O!'
    assert result.find(desired) != -1, 'Wrong game result.'
    
def test_diagonal_0():
    result = basic_test('1\n2\n1\n4\n5\n6\n9\nexit\n')
    desired = 'Winner is X!'
    assert result.find(desired) != -1, 'Wrong game result.'

def test_diagonal_1():
    result = basic_test('1\n2\n7\n1\n5\n9\n3\nexit\n')
    desired = 'Winner is X!'
    assert result.find(desired) != -1, 'Wrong game result.'
    
def test_diagonal_2():
    result = basic_test('1\n2\n4\n1\n3\n5\n8\n9\nexit\n')
    desired = 'Winner is O!'
    assert result.find(desired) != -1, 'Wrong game result.'

def test_diagonal_3():
    result = basic_test('1\n2\n1\n7\n2\n5\n8\n3\nexit\n')
    desired = 'Winner is O!'
    assert result.find(desired) != -1, 'Wrong game result.'
    
def test_draw():
    result = basic_test('1\n2\n1\n2\n3\n5\n4\n7\n6\n9\n8\nexit\n')
    desired = 'Draw!'
    assert result.find(desired) != -1, 'Wrong game result.'
