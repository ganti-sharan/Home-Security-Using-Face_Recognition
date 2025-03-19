import json
import facebook
import requests
import urllib.request as urllib2
import webbrowser
from pprint import pprint

token = "EAAFk4wlmP7kBAIw9XOiqJeWghZBtxle5UE64cXLMx5AZB2ACaMLDOaGRg9d2LX5QppiK515slJfZA6yvObJXZC3qP3Pne8PZAU7g8ctHcPSoyyt5qQ2mt3mPg4Q4ZCpBcOXBUCYk0dFbSscRk7kn4DztC0pQPZBZCXZAxp8kexvkMPsJDYBvLyoHhRKCZCNkRhJ8xT8xRDsZCrZBuQZDZD"
api_url = 'https://graph.facebook.com/v4.0/'
graph = facebook.GraphAPI(token)
PARAMS = {'access-token' : token}

"""def main():
    
    graph = facebook.GraphAPI(token)
    #fields = ['first_name', 'location{location}','email','link']
    profile = graph.get_object('me',fields='first_name,location,link,email')    
    #return desired fields
    print(json.dumps(profile, indent=4))
    extractFriends()
"""  
def extractFriends():
    #call = "me/friends?fields=picture.width(9999).height(9999).type(large),gender,name"
    #URL=api_url+call
    friends = 'https://graph.facebook.com/v4.0/me/friends?access_token='+token
    response = requests.get(friends)
    r = response.json()
    p="https://graph.facebook.com/v4.0/100040329711142/friends?access_token=EAAFk4wlmP7kBAF85so19mdefH8457LuDqxEmJDIcfxjLAKABlCcqY3kZAXbYxpXqA6vFiSwjzgiMYWzZBNsKqolZBWXBfTYxKrRZAfZBga4PI9ZBLsH87huph8lLCCYqMRjtI93QSsZC7UMKiRdgtAZCqxXBZA4sLXyQoxc7CRjbziFM4p73nzIvEhLZA8kn7VoM4ssaS4lfViSmil6yApfZCk4"
    pprint(r)
    response1 = requests.get(p)
    r1 = response1.json()
    pprint(r1)
    for f in r1['data']:
        print(f['name'])
        p_url = str(f['data']['url'])
        print (p_url)
        
        opener1 = urllib2.build_opener()
        page1 = opener1.open(p_url)
        my_picture = page1.read()

        filename = f['name']+"_"+f['id']+".jpg"
        print(filename+" downloaded...")
        fout = open('images/'+filename, "wb")
        fout.write(my_picture)
        fout.close()

extractFriends()
