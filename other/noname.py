import requests
import re
import json
import time
import random
from urllib.parse import unquote

cookies = {
    "__client_id": "6df099f990aef3d57a71118bcc88f52c5078fd16",
    "login_referer": "https%3A%2F%2Fwww.luogu.com.cn%2F",
    "_uid": "818165",
}

headers = {
    "authority": "www.luogu.com.cn",
    "accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7",
    "accept-language": "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6",
    "cache-control": "no-cache",
    # 'cookie': '__client_id=6df099f990aef3d57a71118bcc88f52c5078fd16; login_referer=https%3A%2F%2Fwww.luogu.com.cn%2F; _uid=818165',
    "pragma": "no-cache",
    "referer": "https://www.luogu.com.cn/problem/list?type=CF&keyword=CF1678&page=1",
    "sec-ch-ua": '"Chromium";v="118", "Microsoft Edge";v="118", "Not=A?Brand";v="99"',
    "sec-ch-ua-mobile": "?0",
    "sec-ch-ua-platform": '"Windows"',
    "sec-fetch-dest": "document",
    "sec-fetch-mode": "navigate",
    "sec-fetch-site": "same-origin",
    "sec-fetch-user": "?1",
    "upgrade-insecure-requests": "1",
    "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/118.0.0.0 Safari/537.36 Edg/118.0.2088.76",
}


def check(problem):
    time.sleep(4 + random.random())
    problemURL = "https://www.luogu.com.cn/problem/solution/" + problem

    res = requests.get(problemURL, cookies=cookies, headers=headers)

    content = res.content.decode("utf-8")

    strjson = unquote(re.search('decodeURIComponent\\("(.+?)"\\)', content).group(1))

    jsons = json.loads(strjson)

    return jsons["currentData"]["acceptSolution"]


def get(problem):
    time.sleep(4 + random.random())
    problemURL = "https://www.luogu.com.cn/problem/" + problem

    res = requests.get(problemURL, cookies=cookies, headers=headers)

    content = res.content.decode("utf-8")

    strjson = unquote(re.search('decodeURIComponent\\("(.+?)"\\)', content).group(1))

    jsons = json.loads(strjson)

    with open("oj.json", "w") as f:
        f.write(strjson)

    return (
        problem,
        jsons["currentData"]["problem"]["totalSubmit"],
        jsons["currentData"]["problem"]["difficulty"],
        # jsons["currentData"]["problem"]["wantsTranslation"],
        check(problem),
    )


def add(problem):
    try:
        t = get(problem)
        print(t)

        with open("tijie.txt", "a") as f:
            f.write("%10s %10s %10s %10s\n" % (t[0], t[1], t[2], t[3]))
    except Exception as e:
        print(e)


if __name__ == "__main__":
    for _ in range(1759, 13292 + 1):
        add("UVA%d" % _)

    for _ in range(1, 325 + 1):
        for __ in ["a", "b", "c", "d", "e", "f"]:
            add("AT_abc%03d_%c" % (_, __))

    for _ in range(1678, 1887 + 1): # 我正在跑...
        for __ in ["A", "B", "C", "D", "E"]:
            add("CF%d%c" % (_, __))

    for _ in range(1000, 9814 + 1):
        add("P%d" % _)

    for _ in range(1, 34127 + 1):
        add("SP%d" % _)

