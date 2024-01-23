def convert_currency(amount, from_currency, to_currency, exchange_rates):
  if from_currency == to_currency:
      return amount

  
  if from_currency != 'USD':
      amount = amount / exchange_rates[from_currency]

  
  if to_currency != 'USD':
      amount = amount * exchange_rates[to_currency]

  return amount

def main():
  exchange_rates = {
      'USD': 1.0,
      'EUR': 0.85,
      'GBP': 0.75,
      'INR': 74.50,
      'JPY': 110.00
      
  }

  amount = float(input("Enter the amount: "))
  from_currency = input("Enter the currency to convert from (USD, EUR, GBP, INR, JPY): ").upper()
  to_currency = input("Enter the currency to convert to (USD, EUR, GBP, INR, JPY): ").upper()

  if from_currency in exchange_rates and to_currency in exchange_rates:
      converted_amount = convert_currency(amount, from_currency, to_currency, exchange_rates)
      print(f"{amount} {from_currency} is equal to {converted_amount:.2f} {to_currency}")
  else:
      print("Invalid currency")

if __name__ == "__main__":
  main()
