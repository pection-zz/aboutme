# frozen_string_literal: true

require 'spec_helper'

describe "Cart", type: :feature, inaccessible: true do
  before { create(:store) }

  it "shows cart icon on non-cart pages" do
    visit spree.root_path
    expect(page).to have_selector("li#link-to-cart a", visible: true)
  end

  it "prevents double clicking the remove button on cart", js: true do
    @product = create(:product, name: "RoR Mug")

    visit spree.root_path
    click_link "RoR Mug"
    click_button "add-to-cart-button"

    # prevent form submit to verify button is disabled
    page.execute_script("$('#update-cart').submit(function(){return false;})")

    expect(page).not_to have_selector('button#update-button[disabled]')
    page.find(:css, '.delete img').click
    expect(page).to have_selector('button#update-button[disabled]')
  end

  # Regression test for https://github.com/spree/spree/issues/2006
  it "does not error out with a 404 when GET'ing to /orders/populate" do
    visit '/orders/populate'
    within(".error") do
      expect(page).to have_content(I18n.t('spree.populate_get_error'))
    end
  end

  it 'allows you to remove an item from the cart', js: true do
    create(:product, name: "RoR Mug")
    visit spree.root_path
    click_link "RoR Mug"
    click_button "add-to-cart-button"
    find('.cart-item-delete .delete').click
    expect(page).not_to have_content("Line items quantity must be an integer")
    expect(page).not_to have_content("RoR Mug")
    expect(page).to have_content("Your cart is empty")

    within "#link-to-cart" do
      expect(page).to have_content("EMPTY")
    end
  end

  it 'allows you to empty the cart', js: true do
    create(:product, name: "RoR Mug")
    visit spree.root_path
    click_link "RoR Mug"
    click_button "add-to-cart-button"

    expect(page).to have_content("RoR Mug")
    click_on "Empty Cart"
    expect(page).to have_content("Your cart is empty")

    within "#link-to-cart" do
      expect(page).to have_content("EMPTY")
    end
  end

  # regression for https://github.com/spree/spree/issues/2276
  context "product contains variants but no option values" do
    let(:variant) { create(:variant) }
    let(:product) { variant.product }

    before { variant.option_values.destroy_all }

    it "still adds product to cart", inaccessible: true do
      visit spree.product_path(product)
      click_button "add-to-cart-button"

      visit spree.cart_path
      expect(page).to have_content(product.name)
    end
  end
  it "should have a surrounding element with data-hook='cart_container'" do
    visit spree.cart_path
    expect(page).to have_selector("div[data-hook='cart_container']")
  end
end
