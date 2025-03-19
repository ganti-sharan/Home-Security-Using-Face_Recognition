import face_recognition
import pickle


# Load a sample picture and learn how to recognize it.
shriphad_image = face_recognition.load_image_file('D:\\project\\IMG_3053.jpg')
shriphad_face_encoding = face_recognition.face_encodings(shriphad_image, num_jitters=100)[0]

# Load a second sample picture and learn how to recognize it.
sunny_image = face_recognition.load_image_file('D:\\project\\IMG_3050.jpg')
sunny_face_encoding = face_recognition.face_encodings(sunny_image)[0]

# Create arrays of known face encodings and their names
known_face_encodings = [
    shriphad_face_encoding,
    sunny_face_encoding
]
known_face_names = [
    "Shriphad Rao",
    "Sunny"
 ]
with open("train.pickle", 'wb') as f:
    pickle.dump(known_face_encodings, f)
