#@ Hussein Alshaikhshaker
#Kurs: DT201G
#Laboration: L4_trådar
#Datum: 2024-11-30


import threading
from datetime import datetime
import time

text = ""
writers_waiting = False

readers_lock = threading.Lock()
writer_lock1 = threading.Lock()
writer_lock2 = threading.Lock()

readers_counter = 0
writers_counter = 0

stop_thread = False

def writer(w_id, reverse=False):
    global text, stop_thread, writers_counter, writers_waiting
    while not stop_thread:
        writers_waiting = True
        writer_lock2.acquire()
        writers_counter += 1
        if writers_counter == 1:
            writer_lock1.acquire()
        writers_waiting = False

        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        text = timestamp[::-1] if reverse else timestamp
        print(f"Skrivare {w_id} skriver: {text}")

        writers_counter -= 1
        writer_lock2.release()
        if writers_counter == 0:
            writer_lock1.release()
        time.sleep(1)

def reader(r_id):
    global text, stop_thread, readers_counter, writers_waiting
    while not stop_thread:
        if writers_waiting or writers_counter > 0:
            continue
        readers_lock.acquire()
        readers_counter += 1
        if readers_counter == 1:
            writer_lock1.acquire()
        readers_lock.release()

        print(f"Läsare {r_id} läser: {text}")

        readers_lock.acquire()
        readers_counter -= 1
        if readers_counter == 0:
            writer_lock1.release()
        readers_lock.release()
        time.sleep(1)


def main():
    global stop_thread
    threads = []
    for i in range(3):
        readingthread = threading.Thread(target=reader, args=(i,))
        threads.append(readingthread)
    writingthread1 = threading.Thread(target=writer, args=(1, False))
    writingthread2 = threading.Thread(target=writer, args=(2, True))
    threads.extend([writingthread1, writingthread2])
    for t in threads:
        t.start()
    try:
        time.sleep(5)
    finally:
        stop_thread = True
        for t in threads:
            t.join()
if __name__ == "__main__":
    main()