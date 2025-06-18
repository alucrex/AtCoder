# CCLemon
my_life = 1
enemy_life = 1
my_charge = 0
enemy_charge = 0
option = {
    '1':'charge',
    '2':'beam',
    '3':'barrier'
}

def battle(my_option, enemy_option):
    global my_life
    global enemy_life
    global my_charge
    global enemy_charge
    if my_option == 'beam' and enemy_option == 'barrier': # ビーム対バリア
        my_life -= 1
        my_charge -= 1
        enemy_charge -= 1
        print('あなたは返り討ちに会いました')
    elif my_option == 'barrier' and enemy_option == 'beam': # バリア対ビーム
        enemy_life -= 1
        my_charge -= 1
        enemy_charge -= 1
        print('あなたは相手を返り討ちにしました')
    elif my_option == 'beam' and enemy_option == 'beam': # ビーム対ビーム
        my_charge -= 1
        enemy_charge -= 1
        print('互いのビームが相殺されました')
    elif my_option == 'charge' and enemy_option == 'charge': # チャージ対チャージ
        my_charge += 1
        enemy_charge += 1
        print('あなたはチャージしました')
        print('相手はチャージしました')
    elif my_option == 'charge' and enemy_option == 'beam': # チャージ対ビーム
        my_life -= 1
        my_charge += 1
        enemy_charge -= 1
        print('あなたはビームを受けました')
    elif my_option == 'charge' and enemy_option == 'barrier': # チャージ対バリア
        my_life += 1
        print('あなたはチャージしました')
    elif my_option == 'beam' and enemy_option == 'charge': # ビーム対チャージ
        enemy_life -= 1
        my_charge -= 1
        enemy_charge += 1
        print('相手にビームを当てました')
    elif my_option == 'barrier' and enemy_option == 'charge': # バリア対チャージ
        enemy_charge += 1
        my_charge -= 1
        print('相手はチャージをした')
    elif my_option == 'barrier' and enemy_option == 'barrier': # バリア対バリア
        my_charge -= 1
        enemy_charge -= 1
        print('特に何も起こらなかった')

while True:
    home = input('何をしますか? 1:ccレモンゲームを行う, 2:ccレモンゲームの説明を受ける, 3:ゲームを終了する')
    if home == '1':
        while my_life == 1 and enemy_life == 1:
            print('あなたのチャージ数は{}'.format(my_charge))
            print('相手のチャージ数は{}'.format(enemy_charge))
            my_choice = input('何を選択しますか? 1:チャージ, 2:ビーム, 3:バリア' )
            if my_charge == 0 and my_choice != '1':
                print('チャージが足りません、チャージしてください')
                continue
            if my_choice not in ('1','2','3'): # 選択し意外を選んだ時の処理
                print('1,2,3のどれかを選択してください')
                continue
            if enemy_charge == 0: # 敵の処理
                enemy_choice = '1'
                print(enemy_choice)
            else:
                import random
                enemy_choice = random.choice(list(option.keys()))
            print('あなたは{},相手は{}を選択しました。'.format(my_choice,enemy_choice))
            battle(option[my_choice],option[enemy_choice])
        else:
            if my_life == 0:
                print('あなたの負けです。出直してきてください。')
            elif enemy_life == 0:
                print('あなたの勝ちです。おめでとうございます‼')
    elif home == '2':
        while True:
            explain = input('どの説明を受けますか? 1:ルール概要 2:チャージ 3:ビーム 4:バリア 5:説明を終わる')
            if explain == '1':
                print('ccレモンゲームとは相手にビームを当てたら価値のゲームです。ビームを当てるのに様々な駆け引きを行うのがこのゲームの醍醐味です。')
            elif explain == '2':
                print('チャージとはビームやバリアを行うのに必要なポイントです。チャージしていないと何もできません')
            elif explain == '3':
                print('ビームはチャージを一つ使用して相手を攻撃するコマンドです。相手もビームを行った場合は相殺されて何も起こらなくなります。')
            elif explain == '4':
                print('バリアは相手がビームを打ってきたときに跳ね返すコマンドです。発動するにはチャージを一つ消費します。')
            elif explain == '5':
                break
    elif home == '3':
        break