def solution(array, commands):
    answer = []
    
    for cmd in commands:
        sub_arr = array[cmd[0]-1:cmd[1]]
        sub_arr.sort()
        answer.append(sub_arr[cmd[2]-1])
        
    return answer