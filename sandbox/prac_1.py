import asyncio
import time


async def say_after(delay, what):
    await asyncio.sleep(delay)
    print(what)


async def heavy_calc():
    await asyncio.sleep(5)
    return 1000


async def light_calc():
    await asyncio.sleep(1)
    return 2


async def main():

    task1 = asyncio.create_task(say_after(3, "Hello"))
    task2 = asyncio.create_task(say_after(2, "World"))

    # res = await asyncio.gather(heavy_calc(), light_calc())
    # print(res)

    print(f"started at {time.strftime('%X')}")
    await task1
    print(f"started at {time.strftime('%X')}")
    await task2
    print(f"started at {time.strftime('%X')}")
    await task2


if __name__ == "__main__":
    asyncio.run(main())
