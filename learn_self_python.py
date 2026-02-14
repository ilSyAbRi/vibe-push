class Plant:
    def __init__(self,name,plant_type):
        self.name = name
        self.type = plant_type

    def show_info(self):
        print(f"{self.name} it is type of {self.type}")


plant = Plant("Rose","Flower")
plant.show_info()
