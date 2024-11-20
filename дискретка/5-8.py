def sieve_of_eratosthenes(n):
    sieve = [True] * (n + 1)
    sieve[0] = sieve[1] = False
    
    for i in range(2, int(n**0.5) + 1):
        if sieve[i]:
            for j in range(i*i, n + 1, i):
                sieve[j] = False
                
    return [i for i in range(n + 1) if sieve[i]]

def fermat_factorization(n):
    if n % 2 == 0:
        return 2, n//2
        
    a = int(n**0.5) + 1
    b2 = a*a - n
    while not float(b2**0.5).is_integer():
        a += 1
        b2 = a*a - n
    b = int(b2**0.5)
    return a - b, a + b

def is_prime_fermat(n, k=5):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    
    for _ in range(k):
        a = random.randint(2, n-1)
        if pow(a, n-1, n) != 1:
            return False
    return True

class SimpleSubstitutionCipher:
    def __init__(self, key):
        self.alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя "
        self.key = key
        
    def encrypt(self, text):
        text = text.lower()
        result = ""
        for char in text:
            if char in self.alphabet:
                idx = self.alphabet.index(char)
                result += self.key[idx]
            else:
                result += char
        return result
        
    def decrypt(self, text):
        result = ""
        for char in text:
            if char in self.key:
                idx = self.key.index(char)
                result += self.alphabet[idx]
            else:
                result += char
        return result

def frequency_analysis(text):
    freq = {}
    total = 0
    for char in text:
        if char.isalpha() or char == ' ':
            freq[char] = freq.get(char, 0) + 1
            total += 1
            
    for char in freq:
        freq[char] = freq[char] / total
        
    return dict(sorted(freq.items(), key=lambda x: x[1], reverse=True))

def main_menu():
    while True:
        print("\nВыберите задание:")
        print("1. Код Хемминга")
        print("2. Работа с простыми числами")
        print("3. Шифрование методом замены")
        print("4. Статистический анализ текста")
        print("0. Выход")
        
        choice = input("\nВведите номер задания: ")
        
        if choice == "1":
            k = input("Введите количество информационных разрядов: ")
            data = input(f"Введите {k} битов данных (например, 1101): ")
            hamming = HammingCode()
            encoded = hamming.encode(data)
            print(f"Закодированное сообщение: {encoded}")
            
            error_pos = int(input("Введите позицию для внесения ошибки (от 1 до {len(encoded)}): ")) - 1
            received = list(encoded)
            received[error_pos] = '1' if received[error_pos] == '0' else '0'
            received = ''.join(received)
            print(f"Сообщение с ошибкой: {received}")
            
            error = hamming.detect_error(received)
            print(f"Обнаружена ошибка в позиции: {error}")
            
        elif choice == "2":
            print("\nВыберите операцию:")
            print("1. Найти простые числа до N")
            print("2. Проверить число на простоту")
            subchoice = input("Введите номер операции: ")
            
            if subchoice == "1":
                n = int(input("Введите верхнюю границу N: "))
                primes = sieve_of_eratosthenes(n)
                print(f"Простые числа до {n}: {primes}")
            elif subchoice == "2":
                n = int(input("Введите число для проверки: "))
                if is_prime_fermat(n):
                    print(f"Число {n} вероятно простое")
                else:
                    factors = fermat_factorization(n)
                    print(f"Число {n} составное. Множители: {factors}")
                    
        elif choice == "3":
            key = input("Введите ключ замены (33 символа, включая пробел): ")
            cipher = SimpleSubstitutionCipher(key)
            
            text = input("Введите текст для шифрования: ")
            encrypted = cipher.encrypt(text)
            print(f"Зашифрованный текст: {encrypted}")
            
            decrypted = cipher.decrypt(encrypted)
            print(f"Расшифрованный текст: {decrypted}")
            
        elif choice == "4":
            text = input("Введите текст для анализа: ")
            freq = frequency_analysis(text)
            print("\nЧастоты символов:")
            for char, frequency in freq.items():
                print(f"{char}: {frequency:.3f}")
                
        elif choice == "0":
            break
            
        else:
            print("Неверный выбор. Попробуйте снова.")

if __name__ == "__main__":
    import random
    print("Добро пожаловать в криптографическую программу!")
    main_menu()