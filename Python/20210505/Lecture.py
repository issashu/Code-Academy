#class Customer:
#    cart = "chushki, domati, sirene, maslini, shopska salata, kiufteta"
#    def __init__(self, customer_id):
#        self.customer_id = customer_id
#    
#    def display_cart(self):
#        print(cart)
#    
#class ReturningCustomer(Customer):
#    def order_history(self):
#        print("On 24th March bought....")
#        print("On 1st May bought:", self.cart)
#
#klient = ReturningCustomer(2)
#klient.order_history()

#class Employee:
#    def __init__(self, name, partial):
#        self.employee_name = name
#        self.employment = partial
#    
#    def daily_rate(self):
#        return (8*20)
#
#class PartTimer(Employee):
#    def daily_rate(self):
#        return (4*25)
#    
#
#Name = input("Enter Name:")
#Employment = input("Enter 1 for full-time or 0 for part-time:")
#
#if Employment == 1:
#    rabotnik = Employee(Name, Employment)
#else:
#    rabotnik = PartTimer(Name, Employment)
#
#print(rabotnik.daily_rate())
