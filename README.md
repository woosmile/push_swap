# push_swap

## 과제 목적

- 인자를 특정 명령만을 사용해서 정렬하기
- 단, 명령어의 개수를 최소한으로 사용해야 함

## 학습 내용

- LIS 알고리즘, 그리디 알고리즘
- 시간 복잡도

## 구조체 설명

- t_node : 정렬할 인자들의 자료구조를 양방향 연결 리스트로 구현하기 위한 구조체
    
    ```
    typedef struct s_node
    {
    	int    num;
    	struct s_node    *next;
    	struct s_node    *prev;
    }	t_node;
    ```
    
- t_stack : 양방향 연결 리스트에서 top(head), bot(tail)의 주소값과 인자의 개수를 저장하는 구조체
    
    ```
    typedef struct s_stack
    {
    	int    size;
    	t_node	*top;
    	t_node	*bot;
    }	t_stack;
    ```
    
- t_lis : LIS 알고리즘을 통해 구한 수열의 주소값과 개수를 저장하는 구조체
    
    ```
    typedef struct s_lis
    {
    	int *arr;
    	int length;
    }	t_lis;
    ```
    
- t_cycle : 그리디 알고리즘을 통해 인자의 회전수를 저장하고 인자의 위치를 고려하여 RRA, RA 중 어떤 것을 수행할지 저장하는 구조체
    
    ```
    typedef struct s_cycle
    {
    	int	rev;
    	int	rot;
    	int	rev_temp;
    	int	rot_temp;
    }	t_cycle;
    ```
    
## 함수 설명 (Mandatory Part)

### check_argv

- 인자로 들어온 숫자의 전처리를 담당하는 함수
- 다음과 같은 검사를 진행함
1. 공백으로만 이루어져있는지 (space)
2. 부호 및 숫자 이외의 값이 있는지
3. NULL 확인
4. 중복되는 값이 있는지
5. INT 범위를 초과하는 값이 있는지
- 위 검사에서 이상이 발생하면 Error를 출력하고 exit(1)로 강제 종료

### connect_arg_value

- 문자 성분으로 된 인자들을 숫자로 바꾸고 양방향 연결 리스트로 만들어주는 함수
- 최종적으로 숫자값이 저장된 배열을 확인하면서 양방향 연결 리스트로 만들어줌

### argv_counter

- 인자들의 개수를 세어줌 (split에서 사용하던 방식 재활용)

### argv_to_number

- 문자로된 인자를 숫자로 바꿔주고 int 배열에 할당함 (ft_atoi 인데 int가 아닌 long으로 처리하고 반환함)

### free_av_arr
- ft_split을 통해 구분자인 스페이스로 나누어진 문자배열을 초기화하는 함수


### initial_stack

- 양방향 연결 리스트의 head와 tail을 확인하여 t_stack 구조체 a의 top, bot에 주소값과 a의 사이즈를 할당하고 b의 사이즈를 0으로 초기화함

### op_five_under

- 인자가 5개 이하일 때 사용하는 정렬을 수행하는 함수 (하드코딩)
- 2개, 3개 이하일 때 각각의 경우의 수를 고려하여 고정된 정렬을 수행함
- 4개, 5개인 경우에는 최소값을 b스택에 보내고 a스택에 3개만 남겨놓고 정렬을 수행한 다음 스택 b에서 최소값을 다시 불러오는 방식으로 진행

### op_main

- 5개를 초과하는 인자를 받을 때 정렬을 수행하는 함수, 가장 기본이 되는 함수임
- get_lis_main 함수를 통해서 최장 수열을 구함
    - 이분 탐색을 사용하여 시간 복잡도를 최소화 함 O(NlogN)
    - lis_temp 배열로 record 배열의 값을 구하고 (각 인자마다 lis 수열에 몇번째에 위치할 수 있는지) record 배열을 가장 끝에서부터 시작해서 (가장 큰 값부터 내림차순으로 할당) 최종 lis 값을 구함
    - 단, 인자가 내림차순일 경우에는 lis가 존재하지 않으므로 이러한 경우에만 오름차순으로 정렬하는 함수를 별도로 만듬
- a_to_b 함수로 lis에 포함되지 않는 인자를 b 스택으로 넘겨줌
    - 단, 넘겨줄 때 들어온 인자값들의 평균보다 작으면 그냥 pb, 크면은 pb 후 rb를 해줘서 평균 값을 기준으로 b 스택의 위/아래로 나누었고 이로 인해 회전수가 적은 노드를 구할 때 a 스택의 회전수가 많지 않게 해줌.
- b_to_a 함수로 가장 적은 회전수를 가지는 노드를 매 순간마다 찾아서 a로 넘겨줌
    - 가장 적은 회전수를 가지는 노드를 구할 때, 중간 위치를 기준으로 앞에 있으면 ra, 뒤에 있으면 rra 를 할지 고려해야 하고 rrr, rr도 같이 할 수 있는지 추가적으로 고려해주면 더 적은 명령어를 사용할 수 있음
- align_a : 최소값의 위치를 찾고 ra 또는 rra로 최소값을 top으로 옮겨줘서 정렬을 마침

## 함수 설명 (Bonus Part: Checker)

- 전처리는 mandatory와 같음
- 다만 get_next_line과 같이 read 함수가 사용되었고 잘못된 명령어가 들어오면 Error 표시 후 프로그램을 종료하는 과정이 다름
