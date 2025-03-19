import facebook

token = "EAAFk4wlmP7kBADvi58e901QZBFWFGOZA4UYiESn5uytfEcSZB9zZBtWhb5W3l4ot53daqwM4UeHccGTGZC9LJCwiOm6Ldwlskl8c656ZB7pzrKwbK4bi2eKvMKTEaTs0NYJPPkl1N1a4Hb5QeKzcFzMsJfqVI60pcvlkWjHKI3fJ5DAGRCnFHg2j3vF3IBWr62bVC133ZAAnAZDZD"
 
graph= facebook.GraphAPI(token)
friends= graph.get_object('me')
print(friends["data"])
