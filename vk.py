import time
import vk_api

token = 'TOKEN'
citys = 'Стерлитамак' # Название города точь в точь как в ВКонтакте
age_from = 17 # Возраст [от]
age_to = 18 # Возраст [до]
gender = 'all'  # Пол: [male] - муж, [female] - жен, [all] - не важно
onlines = False  # [True] - только онлайн, [False] - не важно
max_invite = 40 # Сколько максимально отправить заявок за запуск

vk_session = vk_api.VkApi(token=token)
vk = vk_session.get_api()

def send_friend_request(user_id):
    try:
        friends = vk.friends.get()
        if user_id in friends['items']:
            print(f"\033[93mПредупреждение:\033[0m Пользователь с ID {user_id} уже есть в списке друзей.")
            return False
        outgoing_requests = vk.friends.getRequests(out=1)
        if user_id in outgoing_requests['items']:
            print(f"\033[93mПредупреждение:\033[0m Ожидается подтверждение заявки в друзья от пользователя с ID {user_id}.")
            return False
      
        vk.friends.add(user_id=user_id)
        print(f"\033[92mУспешно:\033[0m Заявка в друзья отправлена пользователю с ID {user_id}")
        return True
    except vk_api.exceptions.VkApiError as e:
        if e.code == 14:
            print("\033[91mНеудача:\033[0m Требуется ввод капчи. Обработайте это вручную.")
            return "captcha"
        else:
            print(f"\033[91mНеудача:\033[0m Ошибка при отправке заявки в друзья: {e}")
            return False

def main():
    city_search = vk.database.getCities(country_id=1, q=citys, count=1)
    if city_search['count'] > 0:
        target_city = city_search['items'][0]['id']
    else:
        print("Город не найден")
        return
    
    requests_sent = 0
    while requests_sent < max_invite:
        try:
            gender_value = 1 if gender == 'female' else 2 if gender == 'male' else None
            search_results = vk.users.search(
            count=1000, city=target_city, age_from=age_from, age_to=age_to, online=onlines, sex=gender_value
            )
            for user in search_results['items']:
                result = send_friend_request(user['id'])
                if result == "captcha":
                    return
                elif result:
                    requests_sent += 1
                    if requests_sent >= max_invite:
                        print("\033[92mУспешно:\033[0m Достигнут лимит заявок за день. Скрипт завершает работу.")
                        return
                    print(f"\033[92mУспешно:\033[0m Ожидание 10 минут перед следующей заявкой (заявка {requests_sent}/{max_invite})...")
                    time.sleep(600)
        except vk_api.exceptions.VkApiError as e:
            print(f"\033[91mНеудача:\033[0m Ошибка при выполнении запроса: {e}")
            time.sleep(600)

if __name__ == "__main__":
    main()
    main()